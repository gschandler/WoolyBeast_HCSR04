/*
The MIT License (MIT)

Copyright (c) 2014 Scott Chandler

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef  __WOOLYBEAST_HCSR04__
#define  __WOOLYBEAST_HCSR04__

class WoolyBeast_HCSR04
{
  public:
    WoolyBeast_HCSR04( int triggerPin, int echoPin );
    
    void  begin( int temperatureInCM = 20 );  // air temperature (˚C)
    
    unsigned long  sample(void) const;
    
    enum Scale {
      CM,
      IN
    };
    double  distance( unsigned long duration, Scale scale = CM ) const;
  
  private:
    int             _triggerPin;
    int             _echoPin;
    unsigned long   _soundVelocity;
};


#endif
