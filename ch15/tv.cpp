#include "tv.h"
#include <iostream>

Tv::Tv(int s, int mc)
    : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}

void Tv::onoff() { state = (state == On) ? Off : On; }

bool Tv::ison() const { return state == On; }

bool Tv::volup() {
  if (volume < MaxVal) {
    volume++;
    return true;
  }
  return false;
}

bool Tv::voldown() {
  if (volume > MinVal) {
    volume--;
    return true;
  }
  return false;
}

void Tv::chanup() {
  if (channel < maxchannel) {
    channel++;
  } else {
    channel = 1;
  }
}

void Tv::chandown() {
  if (channel > 1) {
    channel--;
  } else {
    channel = maxchannel;
  }
}

void Tv::set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }

void Tv::set_input() { input = (input == TV) ? DVD : TV; }

void Tv::settings() const {
  std::cout << "TV is " << (state == Off ? "Off" : "On") << '\n';
  if (state == On) {
    std::cout << "Volume setting = " << volume << '\n'
              << "Channel setting = " << channel << '\n'
              << "Mode = " << (mode == Antenna ? "antenna" : "cable") << '\n'
              << "Input = " << (input == TV ? "TV" : "DVD") << '\n';
  }
}

inline void Tv::set_Rmode(Remote &r) {
  r.work_mode =
      (r.work_mode == Remote::Normal) ? Remote::InterActive : Remote::Normal;
}

Remote::Remote(int m) : mode(m) {}

bool Remote::volup(Tv &t) { return t.volup(); }

bool Remote::voldown(Tv &t) { return t.voldown(); }

void Remote::onoff(Tv &t) { t.onoff(); }

void Remote::chanup(Tv &t) { t.chanup(); }

void Remote::chandown(Tv &t) { t.chandown(); }

void Remote::set_chan(Tv &t, int c) { t.channel = c; }

void Remote::set_mode(Tv &t) { t.set_mode(); }

void Remote::set_input(Tv &t) { t.set_input(); }

int Remote::show_mode() const { return work_mode; }
