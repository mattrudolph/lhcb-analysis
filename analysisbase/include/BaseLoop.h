#ifndef BASELOOP_H
#define BASELOOP_H


class BaseLoop {

 public:
  BaseLoop();

  virtual ~BaseLoop() {}

  void printIdx();
  
 private:

  int m_idx;

};

#endif
