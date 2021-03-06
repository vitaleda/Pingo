#pragma once

#include <vector>
#include <vita2d.h>

#include "texture.hpp"
#include "input.hpp"
#include "sound.hpp"
#include "common.hpp"

#include "gui.hpp"

// Forward declaration
class CreditsEntity;

class Credits
{
    public:
        Credits();

        void init();
        void update();
        void draw();

        bool levelHasFaded();
        bool haveEnded();

    private:
        void addElement( CreditsEntity* entity );
        void addEmpty( int height );
        void handleInput();

        struct CreditsElement
        {
            int position;
            CreditsEntity* entity;
        };
        std::vector<CreditsElement> elements;

        float fadePoint;
        float scrollPoint;
        float waitPoint;
        
        float fadeSpeed;
        float scrollSpeed;

        int length;
        float waitTime;

        bool faded;
        bool end;
};

class CreditsEntity
{
    public:
        virtual int getHeight();
        virtual void draw( int height );

    protected:
        int height;
};

class CreditsLogo : public CreditsEntity
{
    public:
        CreditsLogo( vita2d_texture* texture );

        int getHeight() override;
        void draw( int height ) override;

    private:
        vita2d_texture* logo;
        const int paddingBottom = 100;
        const int paddingTop = 50; 
};

class CreditsHeader : public CreditsEntity
{
    public:
        CreditsHeader( const char* text );

        int getHeight() override;
        void draw( int height ) override;

    protected:
        const char* text;
        const int textSize = 40;
        const int paddingBottom = 20;
        const int paddingTop = 30;
};

class CreditsPerson : public CreditsEntity
{
    public:
        CreditsPerson( const char* displayName, const char* role );
        CreditsPerson( const char* displayName );

        int getHeight() override;
        void draw( int height ) override;

    private:
        const char* displayName;
        const char* role;
        const int textSize = 25;
        const int paddingBottom = 20;
        const int spacing = 30;
};

class CreditsTextBlock : public CreditsEntity
{
    public:
        CreditsTextBlock( const char* text );

        int getHeight() override;
        void draw( int height ) override;

    protected:
        const char* text;
        const int textSize = 25;
        const int paddingBottom = 20;
        const unsigned perLine = 40;
};