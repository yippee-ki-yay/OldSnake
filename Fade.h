#ifndef _FADE_H
#define _FADE_H

#include"Image.h"

namespace np
{

class Fade
{
  public:

  enum fadetype{FADEIN,FADEOUT};

  Fade(fadetype f);

  ~Fade();

  void FadeIn(float time);

  void FadeOut(float time);

  void Draw();

   private:

    np::Image *bg;
    float alpha;


};

}

#endif
