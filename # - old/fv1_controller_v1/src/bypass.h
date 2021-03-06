#include <Arduino.h>

#ifndef BYPASS_H
#define BYPASS_H

/**
 * @brief A switch is connected to the µC along with a relay, an opticalrelay and an LED.
 * It has to be setup once, can read the state of the footswitch and swith the state 
 * of the relay/opticalrelay/LED combination. A jumper is also connected and used to set the startup state.
 */
class Bypass
{
    private:
        const uint8_t c_relayPin = 2; // Relay pin #, to be set.
        const uint8_t c_okPin = 1; // Optical relay pin #, to be set.
        const uint8_t c_switchPin = 11; // Footswitch pin #, to be set.
        unsigned long m_now = 0;
        unsigned long m_lastPressTime = 0;
        uint8_t m_bypassState = 0;
        const unsigned int c_debounceTime = 300; // Minimum delay between 2 footswitch press, in ms.

    public:
        /**
         * @brief Setup the µC's pins, read the startup state and set the relay/LED accordingly.
         */
        void bypassSetup();

        /**
         * @brief Read the footswitch state.
         * 
         * @return true if the conditions are met to trigger a bypass
         * @return false 
         */
        bool bypassPressed();

        /**
         * @brief Switch the relay/OK/LED state.
         */
        void switchRelay();

        /**
         * @brief Get the Bypass State object
         * 
         * @return uint8_t 
         */
        uint8_t getBypassState();

        /**
         * @brief Set the Bypass State object
         * 
         * @param state 
         */
        void setBypassState(uint8_t state);
};

#endif