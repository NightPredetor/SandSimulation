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
							"Particle Physics Simulation", sf::Style::Close);
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

				auto btnList = buttonManager.getButtonList();
				for (int i = 0; i < btnList.size(); i++)
				{
					auto const& cellBtn = btnList[i];

					if (cellBtn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						buttonManager.UpdateCellButton(i);
						simulationManager.setCurrentCellIndex(i);
						break;
					}
				}
			}
		}

		// Turn on cells by clicking.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			event.mouseButton.x < simulationManager.getTotalWidth())
		{
			const int BRUSH_SIZE = simulationManager.getBrushSize();

			for (int x = -BRUSH_SIZE; x <= BRUSH_SIZE; x++)
			{
				for (int y = -BRUSH_SIZE; y <= BRUSH_SIZE; y++)
				{
					const auto mousePos = sf::Mouse::getPosition(window);

					int xPos = (mousePos.x + x * simulationManager.getCellSize()) / simulationManager.getCellSize();
					int yPos = (mousePos.y + y * simulationManager.getCellSize()) / simulationManager.getCellSize();

					simulationManager.DrawCell(xPos, yPos);
				}
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

		// Draw brush.
		const auto mousePos = sf::Mouse::getPosition(window);
		window.draw(simulationManager.GetBrushRect(mousePos.x, mousePos.y));

		// Draw UI.
		window.draw(buttonManager.getPauseBtn());
		window.draw(buttonManager.getPauseLabel());
		window.draw(buttonManager.getRestartBtn());
		window.draw(buttonManager.getRestartLabel());
		window.draw(buttonManager.getClearCheckboxBtn());
		window.draw(buttonManager.getClearCheckboxLabel());

		// Draw cell buttons.
		for (const auto& btn : buttonManager.getButtonList())
		{
			window.draw(btn);
		}

		// Draw cell button labels.
		for (const auto& label : buttonManager.getLabelList())
		{
			window.draw(label);
		}

		// FPS.
		fpsHandler.Update();
		window.draw(fpsHandler.getFpsText());

		// End the current frame.
		window.display();

		simulationManager.OnStepTrue();
	}

	return 0;
}