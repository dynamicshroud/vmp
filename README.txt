VMP - Vortex's Music Player

Dependencies:

	- SFML (http://sfml-dev.org)
	- Taglib (http://taglib.org)
	- GNU Make

What is this:

	VMP is a simple-to-use music player using SFML and C++. The
	point of VMP's existence is to show that music players don't
	need to be so complicated.

How to use:

	VMP does not use the mouse yet it uses the keyboard. Here are
	the following key mappings:

	- Space (Pause/Play)
	- Left/Right Arrow (Rewind/Fast Forward)
	- Up/Down Arrow (Volume Up/Down)
	- Q (Quit)

Customization:

	VMP lets the user change a few visual aspects to the program. Such as:

	- Background Color
	- Text Color
	- Font
	- Screen Size

	All of which can be manipulated inside the config.hh file.

	The size of the program on the screen can be changed by editing the
	SCREEN_X and SCREEN_Y variables.

	The background color and the font color can be changed in accordance
	with the SFML color guide (http://sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php).

	The font can be changed by editing the FONT_DIR string with the location
	of your wanted font. The default font is the DejaVu Sans .ttf file
	in the project folder.
