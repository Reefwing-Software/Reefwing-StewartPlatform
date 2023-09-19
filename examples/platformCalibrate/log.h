/******************************************************************
   Serial Print Helper Function

   Usage:  Log::println("Volts", 48.56, "Amps", 68);

   1.1  Write added         22/11/20

   TODO:  Add Log destination (Serial Monitor, Configurator or Black Box)
   
 ******************************************************************/

class Log
{
  public:

    template<typename X>
    static void write(X&& x) {
      if (Serial) { Serial.write(x); }
    }

    template<typename X, typename... Args>
    static void write(X&& x, Args&&... args) {
      if (Serial) { 
        Serial.print(x);
        print(args...);
      }
    }
  
    template<typename X>
    static void print(X&& x) {
      if (Serial) { Serial.print(x); }
    }

    template<typename X, typename... Args>
    static void print(X&& x, Args&&... args) {
      if (Serial) { 
        Serial.print(x);
        print(args...);
      }
    }

    template<typename X>
    static void println(X&& x) {
      if (Serial) { Serial.println(x); }
    }

    template<typename X, typename... Args>
    static void println(X&& x, Args&&... args) { 
      if (Serial) { 
        Serial.print(x);
        println(args...);
      }
    }
};