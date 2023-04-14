#pragma once
#include <SFML/Graphics.hpp>

class ButtonManager
{
public:
	ButtonManager(const int width, const int cellSize);

	void UpdatePauseBtn(const bool isSimulationPaused);
	void UpdateCheckboxLabel(const bool clearBoard);

	sf::RectangleShape getPauseBtn() const;
	sf::Text getPauseLabel() const;

	sf::RectangleShape getStepBtn() const;
	sf::Text getStepLabel() const;

	sf::RectangleShape getRestartBtn() const;
	sf::Text getRestartLabel() const;

	sf::RectangleShape getClearCheckboxBtn() const;
	sf::Text getClearCheckboxLabel() const;

private:
	sf::Font font;

	float width;
	float cellSize;

	sf::RectangleShape pauseBtn;
	sf::Text pauseLabel;

	sf::RectangleShape stepBtn;
	sf::Text stepLabel;

	sf::RectangleShape restartBtn;
	sf::Text restartLabel;

	sf::RectangleShape clearCheckboxBtn;
	sf::Text clearCheckboxLabel;

	void SetupPauseButton();
	void SetupStepButton();
	void SetupRestartButton();
	void SetupClearButton();
};