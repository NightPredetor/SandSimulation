#include <SFML/Graphics.hpp>
#include <iostream>

#include "SimulationManager.h"
#include "ButtonManager.h"
#include "Internal/FPS.h"

int main()
{
	SimulationManager simulationManager;
	ButtonManager buttonManager(simulationManager.getWidth(), simulationManager.getCellSize());

	// Setup clock for FPS.
	FPS fpsHandler;
	fpsHandler.SetFpsTextPosition(simulationManager.getTotalWidth() + 60, 10);

	// Create window.
	sf::RenderWindow window(sf::VideoMode(simulationManager.getTotalWidth() + simulationManager.getUiSpace(),
							simulationManager.getTotalLength()),
							"Conway's Game of Life", sf::Style::Close);
	window.setFramerateLimit(60);
	window.hasFocus();

	// SFML loop.
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed &&
					 event.mouseButton.button == sf::Mouse::Left)
			{
				// UI logic.
				if (buttonManager.getPauseBtn().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					simulationManager.TogglePause();
					buttonManager.UpdatePauseBtn(simulationManager.getPauseSimulation());
				}
				else if (simulationManager.getPauseSimulation() && buttonManager.getStepBtn().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					simulationManager.PerformStep();
				}
				else if (buttonManager.getRestartBtn().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					simulationManager.OnRestart();
					buttonManager.UpdatePauseBtn(simulationManager.getPauseSimulation());
				}
				else if (buttonManager.getClearCheckboxBtn().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					simulationManager.ToggleClearBoard();
					buttonManager.UpdateCheckboxLabel(simulationManager.getClearBoard());
				}
			}
		}

		// Turn on cells by clicking.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
			sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (event.mouseButton.x < simulationManager.getTotalWidth())
			{
				const auto mousePos = sf::Mouse::getPosition(window);

				int xPos = mousePos.x / simulationManager.getCellSize();
				int yPos = mousePos.y / simulationManager.getCellSize();
				Vector2 cellPos(xPos, yPos);

				// Left click generates sand cells,
				// Right click generates wall cells.
				bool isLeftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
				simulationManager.ToggleCellState(cellPos, isLeftClick);
			}
		}

		// Clear the window.
		window.clear(sf::Color::Black);

		// Draw cell BG.
		window.draw(simulationManager.getCellBg());

		if (simulationManager.getPauseSimulation() == false)
		{
			// Cell state logic.
			simulationManager.UpdateCells();
		}
		else
		{
			window.draw(buttonManager.getStepBtn());
			window.draw(buttonManager.getStepLabel());
		}

		// Cell draw logic.
		window.draw(simulationManager.GetCellsForDraw());

		// Draw UI.
		window.draw(buttonManager.getPauseBtn());
		window.draw(buttonManager.getPauseLabel());
		window.draw(buttonManager.getRestartBtn());
		window.draw(buttonManager.getRestartLabel());
		window.draw(buttonManager.getClearCheckboxBtn());
		window.draw(buttonManager.getClearCheckboxLabel());

		// FPS.
		fpsHandler.Update();
		window.draw(fpsHandler.getFpsText());

		// End the current frame.
		window.display();

		simulationManager.OnStepTrue();
	}

	return 0;
}