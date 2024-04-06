#ifndef SIGNALDATA_H
#define SIGNALDATA_H


struct SignalData {
    double amplitude;
    double frequency;  // Assuming frequency is measured in Hertz (Hz)
     // Assuming amplitude is a unitless quantity

    // Default constructor
    SignalData() : amplitude(0.0), frequency(0.0){}

    // Parameterized constructor
    SignalData(double freq, double amp) :amplitude(amp),frequency(freq) {}
};
#endif // SIGNALDATA_H
