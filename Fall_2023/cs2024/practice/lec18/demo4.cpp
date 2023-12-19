// CS2024 Lecture 18, Demo #4
//
// Using const_cast<>
//

#include <iostream>
#include <cstring>
using namespace std;

// Here are my global variables


class ColorNames 
{
    public:
        enum ColorCode
        {
            kRed,
            kGreen,
            kYellow,
            kBlue,
        };

    ColorNames()
    {
        strcpy(colorNames[kRed],"red");
        strcpy(colorNames[kGreen],"green");
        strcpy(colorNames[kYellow],"yellow");
        strcpy(colorNames[kBlue],"blue");
    }

    // getColorName takes a ColorCode and returns the C-style string
    // representation of that color
    const char *getColorName(ColorCode color)
    {
        return colorNames[color];
    }

    private:
        char colorNames[5][7];
};

int main (int argc, char * const argv[])
{
    ColorNames colorNames;
    // OK, let's get a color name and use const_cast<> 
	// to change it!
	
	// This is how we're SUPPOSED to use getColorName... to
	// simply retrieve a color name and use it in a "read only"
	// manner
    const char *colorName = colorNames.getColorName(colorNames.kBlue);

    // This next line should be a compiler error, because I'm attempting
	// to write to a const location
    // colorName[0] = 'B';
    cout << "kBlue is associated with the color name: " << colorName << endl;

    // But now, being the renegade that I am, I would like to capitalize
	// the color name before printing it out...
    char *redColorName = const_cast<char *>(colorNames.getColorName(colorNames.kRed));

    // This still cases problems, but the code is legal
    redColorName[0] = 'R';
    cout << "kRed is associated with the color name: " << redColorName << endl;

    return 0;
}