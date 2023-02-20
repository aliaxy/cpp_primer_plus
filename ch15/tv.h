#ifndef TV_H_
#define TV_H_

class Remote;

class Tv {
public:
  friend class Remote;
  enum { Off, On };
  enum { MinVal, MaxVal = 20 };
  enum { Antenna, Cable };
  enum { TV, DVD };

  Tv(int = Off, int = 125);
  void onoff();
  bool ison() const;
  bool volup();
  bool voldown();
  void chanup();
  void chandown();
  void set_mode();
  void set_input();
  void settings() const;
  void set_Rmode(Remote &);

private:
  int state;
  int volume;
  int maxchannel;
  int channel;
  int mode;
  int input;
};

class Remote {
public:
  enum { Normal, InterActive };

private:
  int mode;
  int work_mode;

public:
  friend class Tv;
  Remote(int = Tv::TV);
  bool volup(Tv &);
  bool voldown(Tv &);
  void onoff(Tv &);
  void chanup(Tv &);
  void chandown(Tv &);
  void set_chan(Tv &, int);
  void set_mode(Tv &);
  void set_input(Tv &);
  int show_mode() const;
};

#endif