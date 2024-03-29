#include "ButtonManager.h"

#include <array>

// ----- Public -----

ButtonManager::ButtonManager(const int width, const int cellSize) : width(width), cellSize(cellSize)
{
	// Load font.
	font.loadFromFile("Resources/Font/arial.ttf");

	SetupPauseButton();
	SetupStepButton();
	SetupRestartButton();
	SetupClearButton();

	SetupButtonList();
	UpdateCellButton(1);
}

sf::RectangleShape ButtonManager::getPauseBtn() const { return pauseBtn; }

sf::Text ButtonManager::getPauseLabel() const { return pauseLabel; }

sf::RectangleShape ButtonManager::getStepBtn() const { return stepBtn; }

sf::Text ButtonManager::getStepLabel() const { return stepLabel; }

sf::RectangleShape ButtonManager::getRestartBtn() const { return restartBtn; }

sf::Text ButtonManager::getRestartLabel() const { return restartLabel; }

sf::RectangleShape ButtonManager::getClearCheckboxBtn() const { return clearCheckboxBtn; }

sf::Text ButtonManager::getClearCheckboxLabel() const { return clearCheckboxLabel; }

std::vector<sf::RectangleShape> ButtonManager::getButtonList() const { return btnList; }

std::vector<sf::Text> ButtonManager::getLabelList() const { return labelList; }

void ButtonManager::UpdatePauseBtn(const bool isSimulationPaused)
{
	if (isSimulationPaused)
	{
		pauseBtn.setPosition(width * cellSize + (25 + 10), 50);

		pauseLabel.setString("Unpause");
		pauseLabel.setPosition(width * cellSize + (35 + 10), 50 + 10);
	}
	else
	{
		pauseBtn.setPosition(width * cellSize + 50, 50);

		pauseLabel.setString("Pause");
		pauseLabel.setPosition(width * cellSize + (50 + 20), 50 + 10);
	}
}

void ButtonManager::UpdateCheckboxLabel(const bool clearBoard)
{
	std::string result = clearBoard ? "True" : "False";
	clearCheckboxLabel.setString("Clear:\n" + result);
}

void ButtonManager::UpdateCellButton(const int newIndex)
{
	if (newIndex >= 0 && newIndex < btnList.size())
	{
		btnList[currentCellBtnIndex].setFillColor(sf::Color::White);
		btnList[newIndex].setFillColor(sf::Color::Green);

		currentCellBtnIndex = newIndex;
	}
}

// ----- Private -----

void ButtonManager::SetupPauseButton()
{
	// Create pause button.
	pauseBtn = sf::RectangleShape(sf::Vector2f(100, 50));
	pauseBtn.setPosition(width * cellSize + 50, 50);
	pauseBtn.setFillColor(sf::Color::White);

	// Create pause label.
	pauseLabel = sf::Text("Pause", font);
	pauseLabel.setCharacterSize(20);
	pauseLabel.setFillColor(sf::Color::Black);
	pauseLabel.setPosition(width * cellSize + (50 + 20), 50 + 10);
}

void ButtonManager::SetupStepButton()
{
	// Create step button.
	stepBtn = sf::RectangleShape(sf::Vector2f(20, 50));
	stepBtn.setPosition(width * cellSize + 145, 50);
	stepBtn.setFillColor(sf::Color::White);

	// Create step label.
	stepLabel = sf::Text("+", font);
	stepLabel.setCharacterSize(20);
	stepLabel.setFillColor(sf::Color::Black);
	stepLabel.setPosition(width * cellSize + 150, 60);
}

void ButtonManager::SetupRestartButton()
{
	// Create restart button.
	restartBtn = sf::RectangleShape(sf::Vector2f(100, 50));
	restartBtn.setPosition(width * cellSize + 20, 125);
	restartBtn.setFillColor(sf::Color::White);

	// Create restart label.
	restartLabel = sf::Text("Restart", font);
	restartLabel.setCharacterSize(20);
	restartLabel.setFillColor(sf::Color::Black);
	restartLabel.setPosition(width * cellSize + (20 + 15), 125 + 10);
}

void ButtonManager::SetupClearButton()
{
	// Create clear button.
	clearCheckboxBtn = sf::RectangleShape(sf::Vector2f(60, 35));
	clearCheckboxBtn.setPosition(width * cellSize + 130, 130);
	clearCheckboxBtn.setFillColor(sf::Color::White);

	// Create clear label.
	clearCheckboxLabel = sf::Text("Clear:\nFalse", font);
	clearCheckboxLabel.setCharacterSize(15);
	clearCheckboxLabel.setFillColor(sf::Color::Black);
	clearCheckboxLabel.setPosition(width * cellSize + 140, 130);
}

void ButtonManager::SetupButtonList()
{
	const float OFFSET = 75;
	const std::array<std::string, 4> labelNameArray = { "Erase", "Sand", "Water", "Stone" };

	for (int i = 0; i < labelNameArray.size(); i++)
	{
		// Set button.
		auto btn = sf::RectangleShape(sf::Vector2f(100, 50));
		btn.setPosition(width * cellSize + 50, 225 + OFFSET * i);
		btn.setFillColor(sf::Color::White);

		btnList.push_back(btn);

		// Set label.
		auto label = sf::Text(labelNameArray[i], font);
		label.setCharacterSize(20);
		label.setFillColor(sf::Color::Black);
		label.setPosition(width * cellSize + (60 + 15), 225 + 10 + OFFSET * i);

		labelList.push_back(label);
	}
}
