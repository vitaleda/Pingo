#pragma once

#include <vector>
#include <string>

#include <vita2d.h>

#include "level.hpp"
#include "gui.hpp"
#include "input.hpp"
#include "common.hpp"

class MenuItem
{
    public:
        MenuItem();
        MenuItem( Rect rect, std::string label );

        // Draw the menu item
        virtual void draw();

        // Draw the menu item the cursor is currently at
        virtual void drawSelected();

    protected:
        bool selected;
        Rect rect;
        std::string label;
};

class Menu
{
    public:
        Menu();

        void addItem( MenuItem item );

        virtual void update();

        virtual void draw();

        // Returns cursor location
        int getCursor();

    protected:
        std::vector<MenuItem> menuItems;
        int cursor;

        // Handles all input from user
        void handleInput();

        // Returns select value
        bool selectPressed();

        // Move the cursor
        void selectUp();
        void selectDown();
};

class MainMenu : public Menu
{
    public:
        MainMenu();

        void draw() override;

        // Returns true if the button was clicked
        bool clickedStart();
        bool clickedExit();
};

class PauseMenu : public Menu
{
    public:
        PauseMenu();

        void draw() override;

        // Returns true if the button was clicked
        bool clickedResume();
        bool clickedMainMenu();
};

class LevelFinish : public Menu
{
    public:
        LevelFinish();

        void draw() override;

        // Returns true if the button was clicked
        bool clickedNextLevel();
        bool clickedMainMenu();
};


class LevelSelectItem
{
    public:
        LevelSelectItem();
        LevelSelectItem( Rect rect, std::string label );

        // Draw the menu item
        virtual void draw();

        // Draw the menu item the cursor is currently at
        virtual void drawSelected();

    protected:
        bool selected;
        Rect rect;
        std::string label;
};

class LevelSelect
{
    public:
        LevelSelect();

        void initLevels( LevelList levelList );

        void update();
        void draw();

        // Returns cursor location
        Vec2 getCursor();

    protected:
        std::vector< LevelSelectItem > menuItems;
        Vec2 cursor;

        // Handles all input from user
        void handleInput();

        // Returns select value
        bool selectPressed();

        // Move the cursor
        void selectUp();
        void selectRight();
        void selectDown();
        void selectLeft();
};