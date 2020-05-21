#include "Utils.h"
#include <ctype.h>
#include <string>
void Normalize255RGB(GLfloat *rgbs)
{
    for (int i = 0; i < 3; ++i)
        rgbs[i] /= 255.0f;
}

int char2int(char c)
{
    if('0'<=c && c<='9')
        return c-'0';
    else if('A'<=c&&c<='F')
        return c-55;
    return 0;
}

GLfloat *ParseColorString(const char *ColorString)
{
    auto len = strlen(ColorString);
    if (len == 0)
        return NULL;
    int begin = ColorString[0] == '#' ? 1 : 0;
    bool has_prefix = begin;
    len -= begin;
    if (!(len == 6 || len == 8))
        return NULL;
    GLfloat *result = new GLfloat[len / 2];
    if (len == 8)
    {
        auto alpha_value = char2int(toupper(ColorString[begin])) * 16 + char2int(toupper(ColorString[begin + 1]));
        result[3] = alpha_value;
        begin += 2;
    }
    int place_value_index = 0;
    for (int i = begin; i < len; i += 2)
    {
        result[place_value_index++] = char2int(toupper(ColorString[i])) * 16 + char2int(toupper(ColorString[i + 1]));
    }
    return result;
}