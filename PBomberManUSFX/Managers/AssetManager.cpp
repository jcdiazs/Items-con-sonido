#include <SDL_image.h>
#include <iostream>

#include "../Managers/AssetManager.h"

void AssetManager::load(SDL_Renderer* renderer)
{
        // load font
    loadFont();
    loadFont1();
    loadFont2();
    // load textures
    loadTexture(renderer, GameTexture::MenuBack, "assets/title.png");
    loadTexture(renderer, GameTexture::Metal, "resources/muro_metal.jpg");
    loadTexture(renderer, GameTexture::Stone, "resources/muro_piedra_01.png");
    loadTexture(renderer, GameTexture::CartoonStone, "resources/cartoonstone.png");
    loadTexture(renderer, GameTexture::RealStone, "resources/realstone.png");
    loadTexture(renderer, GameTexture::CustomStone, "resources/customstone.png");
    loadTexture(renderer, GameTexture::Grass, "resources/suelo_cesped_01.png");
    loadTexture(renderer, GameTexture::RealGrass, "resources/realgrass.png");
    loadTexture(renderer, GameTexture::CartoonGrass, "resources/cartoongrass.png");
    loadTexture(renderer, GameTexture::CustomGrass, "resources/customgrass.png");
    loadTexture(renderer, GameTexture::Brick, "resources/muro_ceramica_01.png");
    loadTexture(renderer, GameTexture::CartoonBrick, "resources/cartoonbrick.png");
    loadTexture(renderer, GameTexture::CustomBrick, "resources/custombrick.png");
    loadTexture(renderer, GameTexture::RealBrick, "resources/realbrick.png");
    loadTexture(renderer, GameTexture::WallPacman, "resources/wall_sprite.bmp");
    loadTexture(renderer, GameTexture::Skins, "assets/skins.png");
    loadTexture(renderer, GameTexture::Player1, "assets/player1.png");
    loadTexture(renderer, GameTexture::Player2, "assets/player2.png");
    loadTexture(renderer, GameTexture::Player3, "assets/player3.png");
    loadTexture(renderer, GameTexture::Player4, "assets/player4.png");
    loadTexture(renderer, GameTexture::Player5, "assets/player5.png");
    loadTexture(renderer, GameTexture::Player6, "assets/player6.png");
    loadTexture(renderer, GameTexture::TpItem, "assets/Teleport.png");
    loadTexture(renderer, GameTexture::HeartItem, "assets/heart.png");
    loadTexture(renderer, GameTexture::SkullItem, "assets/skull.png");
    loadTexture(renderer, GameTexture::RayoItem, "assets/rayo.png");
    loadTexture(renderer, GameTexture::TurtleItem, "assets/turtle.png");
    loadTexture(renderer, GameTexture::RelojItem, "assets/reloj.png");
    loadTexture(renderer, GameTexture::HourglassItem, "assets/hourglass.png");
    loadTexture(renderer, GameTexture::MedalItem, "assets/medal.png");
    loadTexture(renderer, GameTexture::Enemy1, "assets/enemy_1.png");
    loadTexture(renderer, GameTexture::Enemy2, "assets/enemy_2.png");
    loadTexture(renderer, GameTexture::Enemy3, "assets/enemy_3.png");
    loadTexture(renderer, GameTexture::Enemy4, "assets/enemy_4.png");
    loadTexture(renderer, GameTexture::Bomb, "assets/bomb.png");
    loadTexture(renderer, GameTexture::Explosion, "assets/explosion.png");
    loadTexture(renderer, GameTexture::Door, "assets/door.png");
    // load music
   // loadMusic(MusicEnum::MainMenu, "assets/main_theme.ogg");
    loadMusic(MusicEnum::MainMenu, "assets/EscenaRank.mp3");
    //loadMusic(MusicEnum::Level, "assets/level.ogg");
    loadMusic(MusicEnum::Level, "assets/mcr2.mp3");
    // load sounds
    loadSound(SoundEnum::Win, "assets/win.wav");
    loadSound(SoundEnum::Lose, "assets/lose.wav");
    loadSound(SoundEnum::Explosion, "assets/explosion.wav");

    loadSound(SoundEnum::Door, "assets/explosion.wav");
    loadSound(SoundEnum::Teleport, "assets/explosion.wav");
    loadSound(SoundEnum::Vida, "assets/explosion.wav");
    loadSound(SoundEnum::AntiVida, "assets/explosion.wav");
    loadSound(SoundEnum::Rayo, "assets/explosion.wav");
    loadSound(SoundEnum::Tortuga, "assets/explosion.wav");
    loadSound(SoundEnum::AntiTiempo, "assets/explosion.wav");
    loadSound(SoundEnum::Velocidad, "assets/explosion.wav");
    loadSound(SoundEnum::Tiempo, "assets/explosion.wav");

    if (auto explosionSound = getSound(SoundEnum::Explosion))
    {
        Mix_VolumeChunk(explosionSound.get(), 35);
    }
}

std::shared_ptr<TTF_Font> AssetManager::getFont() const
{
    return font;
}

std::shared_ptr<TTF_Font> AssetManager::getFont1() const
{
    return font1;
}

std::shared_ptr<TTF_Font> AssetManager::getFont2() const
{
    return font2;
}

std::shared_ptr<SDL_Texture> AssetManager::getTexture(GameTexture texture)
{
    return textures[texture];
}

std::shared_ptr<Mix_Music> AssetManager::getMusic(MusicEnum music)
{
    return musics[music];
}

std::shared_ptr<Mix_Chunk> AssetManager::getSound(SoundEnum sound)
{
    return sounds[sound];
}

void AssetManager::loadFont()
{
    // load font
    font = std::shared_ptr<TTF_Font>(TTF_OpenFont("assets/bman.ttf", 32), TTF_CloseFont);
    if(!font)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    }
}

void AssetManager::loadFont1()
{
    // load font
    font1 = std::shared_ptr<TTF_Font>(TTF_OpenFont("assets/bman.ttf", 24), TTF_CloseFont);
    if (!font1)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    }
}

void AssetManager::loadFont2()
{
    // load font
    font2 = std::shared_ptr<TTF_Font>(TTF_OpenFont("assets/Hearts.ttf", 32), TTF_CloseFont);
    if (!font2)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    }
}

void AssetManager::loadTexture(SDL_Renderer* renderer, GameTexture texture, const std::string& filePath)
{
    textures[texture] =
        std::shared_ptr<SDL_Texture>(IMG_LoadTexture(renderer, filePath.c_str()), SDL_DestroyTexture);
    if(!textures[texture])
    {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
}

void AssetManager::loadMusic(MusicEnum music, const std::string& filePath)
{
    musics[music] = std::shared_ptr<Mix_Music>(Mix_LoadMUS(filePath.c_str()), Mix_FreeMusic);
    if(!musics[music])
    {
        std::cout << "loadMusic Error: " << Mix_GetError() << std::endl;
    }
}

void AssetManager::loadSound(SoundEnum sound, const std::string& filePath)
{
    sounds[sound] = std::shared_ptr<Mix_Chunk>(Mix_LoadWAV(filePath.c_str()), Mix_FreeChunk);
    if(!sounds[sound])
    {
        std::cout << "loadSound Error: " << Mix_GetError() << std::endl;
    }
}
