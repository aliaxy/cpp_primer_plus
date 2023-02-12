const int Len = 40;

struct golf {
  char fullname[Len];
  int headicap;
};

void setgolf(golf &g, const char *name, int hc);

int setgolf(golf &g);

void handica(golf &g, int hc);

void showgolf(const golf &g);