[Prev] Table Of Contents [Next]
Using the Simple DirectMedia Layer API
Video

    * Choosing and setting video modes (the easy way)

          You just choose your favorite bit-depth and resolution, and set it!

	Tip #1:
You can find the fastest video depth supported by the hardware with the function SDL_GetVideoInfo().

Tip #2:
You can get a list of supported video resulutions at a particular bit-depth using the function SDL_ListModes().
Example:

{ SDL_Surface *screen;

    screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
    if ( screen == NULL ) {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        exit(1);
    }
}

    * Drawing pixels on the screen

          Drawing to the screen is done by writing directly to the graphics framebuffer, and calling the screen update function.

	Tip:
If you know that you will be doing a lot of drawing, it is best to lock the screen (if necessary) once before drawing, draw while keeping a list of areas that need to be updated, and unlock the screen again before updating the display.
Example:

Drawing a pixel on a screen of arbitrary format

void DrawPixel(SDL_Surface *screen, Uint8 R, Uint8 G, Uint8 B)
{
    Uint32 color = SDL_MapRGB(screen->format, R, G, B);

    if ( SDL_MUSTLOCK(screen) ) {
        if ( SDL_LockSurface(screen) < 0 ) {
            return;
        }
    }
    switch (screen->format->BytesPerPixel) {
        case 1: { /* Assuming 8-bpp */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *bufp = color;
        }
        break;

        case 2: { /* Probably 15-bpp or 16-bpp */
            Uint16 *bufp;

            bufp = (Uint16 *)screen->pixels + y*screen->pitch/2 + x;
            *bufp = color;
        }
        break;

        case 3: { /* Slow 24-bpp mode, usually not used */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *(bufp+screen->format->Rshift/8) = R;
            *(bufp+screen->format->Gshift/8) = G;
            *(bufp+screen->format->Bshift/8) = B;
        }
        break;

        case 4: { /* Probably 32-bpp */
            Uint32 *bufp;

            bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x;
            *bufp = color;
        }
        break;
    }
    if ( SDL_MUSTLOCK(screen) ) {
        SDL_UnlockSurface(screen);
    }
    SDL_UpdateRect(screen, x, y, 1, 1);
}

    * Loading and displaying images

          SDL provides a single image loading routine for your convenience, SDL_LoadBMP(). A library for image loading can be found in the SDL demos archive.

          You can display images by using SDL_BlitSurface() to blit them into the graphics framebuffer. SDL_BlitSurface() automatically clips the blit rectangle, which should be passed to SDL_UpdateRects() to update the portion of the screen which has changed.

	Tip #1:
If you are loading an image to be displayed many times, you can improve blitting speed by convert it to the format of the screen. The function SDL_DisplayFormat() does this conversion for you.

Tip #2:
Many sprite images have a transparent background. You can enable transparent blits (colorkey blit) with the SDL_SetColorKey() function.
Example:

void ShowBMP(char *file, SDL_Surface *screen, int x, int y)
{
    SDL_Surface *image;
    SDL_Rect dest;

    /* Load the BMP file into a surface */
    image = SDL_LoadBMP(file);
    if ( image == NULL ) {
        fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
        return;
    }

    /* Blit onto the screen surface.
       The surfaces should not be locked at this point.
     */
    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;
    SDL_BlitSurface(image, NULL, screen, &dest);

    /* Update the changed portion of the screen */
    SDL_UpdateRects(screen, 1, &dest);
}

[Prev] Table Of Contents [Next]
