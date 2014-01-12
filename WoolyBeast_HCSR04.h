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
