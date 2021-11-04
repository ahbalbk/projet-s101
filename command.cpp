#include "command.h"
#include "ppmio.h"
#include <vector>
#include <string>

void copy(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{
    writePicture(path, red, green, blue);
}

void rmColor(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{

}

void searchColor(const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

void neg(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

void bin(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

void lum(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}
