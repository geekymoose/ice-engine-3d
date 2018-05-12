#pragma once

#include "utils/log.h"
#include "utils/Singleton.h"
#include "utils/constants.h"

#include <chrono>
#include <thread>

namespace ice {


/**
 * The famouse and beautiful TimeManager.
 * Deals with game time, FPS.
 *
 * \date    May 2018
 * \author  Constantin
 */
class TimeManager : private Singleton<TimeManager> {

    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------
    private:
        typedef std::chrono::steady_clock       Clock;
        typedef std::chrono::time_point<Clock>  TimePoint;

        const float _fixedFPS       = ICE_FIXED_FPS;
        const float _fixedDeltaTime = ICE_FIXED_DELTATIME;

        int         _currentFPS = 0;            // The FPS
        float       _currentDeltaTime = 0.0f;   // Delta Time in seconds
        TimePoint   _currentStartFrame;         // TimePoint start frame
        TimePoint   _lastFixedFrame;            // Last time physics done
        bool        _hasFixedUpdate = false;    // True if next loop need fixed

    // Singleton elt
    private:
        TimeManager() = default;
        friend Singleton<TimeManager>;
    public:
        using Singleton<TimeManager>::getInstance;


    // -------------------------------------------------------------------------
    // Core (Like metalcore, or deathcooooore!!)
    // -------------------------------------------------------------------------

    public:
        void startup() {
            LOG << "Startup TimeManager\n";
            _currentStartFrame = Clock::now();
            _lastFixedFrame = _currentStartFrame;
        }

        void shutdown() {
            LOG << "Shutdown TimeManager\n";
        }


    public:

        /**
         * To call at the beginning of the main loop.
         * Update all time data relative to the beginning of the frame.
         */
        void update() {
            TimePoint previous = _currentStartFrame;
            _currentStartFrame = Clock::now();

            std::chrono::duration<float> elapsed = _currentStartFrame - previous;
            std::chrono::duration<float> elapsedFixed = _currentStartFrame - _lastFixedFrame;

            _currentDeltaTime = elapsed.count();
            _currentFPS = static_cast<int>(1 / _currentDeltaTime);

            _hasFixedUpdate = false;
            if(elapsedFixed.count() >= _fixedDeltaTime) {
                _lastFixedFrame = _currentStartFrame;
                _hasFixedUpdate = true;
            }
        }

        /**
         * Check whether the current frame also has a fixed update to do.
         * Means a physic update is required.
         */
        bool hasFixedUpdate() {
            return _hasFixedUpdate;
        }


    // -------------------------------------------------------------------------
    // Data getters and utils
    // -------------------------------------------------------------------------

    public:

        float getCurrentFPS() {
            return _currentFPS;
        }

        float getDeltaTime() {
            return _currentDeltaTime;
        }

        float getFixedDeltaTime() {
            return _fixedDeltaTime;
        }
};

} // End namespace
