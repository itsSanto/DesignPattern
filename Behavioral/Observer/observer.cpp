/*
Defines one to many dependency b/w objects
*/

#include <iostream>
#include <vector>

class Observer {
public:
  Observer(Car *car) : mCar(car) { mCar->attach(this); }
  virtual void update() {}
  Car *getCar() { return mCar; }

private:
  Car *mCar;
};

class Car {
public:
  void notify() {
    for (const auto obs : mObserverList) {
      obs->update();
    }
  }

  int getPosition() { return position; }

  void setPosition(int newPosition) {
    position = newPosition;
    notify();
  }

  void attach(Observer *obs) { mObserverList.push_back(obs); }

  void detach(Observer *obs) {
    mObserverList.erase(
        std::remove(mObserverList.begin(), mObserverList.end(), obs),
        mObserverList.end());
  }

private:
  int position;
  std::vector<Observer *> mObserverList;
};

class LeftObserver : public Observer {
  LeftObserver(Car *car) : Observer(car) {}
  void update() {
    auto pos = Observer::getCar()->getPosition();
    if (pos > 0) {
      std::cout << "Left Side.\n";
    }
  }
};

class RightObserver : public Observer {
public:
  RightObserver(Car *car) : Observer(car) {}
  void update() {
    auto pos = getCar()->getPosition();
    if (pos < 0) {
      std::cout << "Right Side.\n";
    }
  }
};

class MiddleObserver : public Observer {
public:
  MiddleObserver(Car *car) : Observer(car) {}
  void update() {
    auto pos = getCar()->getPosition();
    if (pos < 0) {
      std::cout << "Middle Side.\n";
    }
  }
};

int main() {
  Car *car = new Car();
  LeftObserver leftObserver(Car);
  RightObserver rightObserver(Car);
  MiddleObserver middleObserver(Car);

  char pressedButton;
  bool breakLoop = false;

  while (breakLoop) {
    std::cin >> pressedButton;
    switch (pressedButton) {
    case 108:
      car->setPosition(-1);
      break;
    case 99:
      car->setPosition(0);
      break;
    case 114:
      car->setPosition(1);
      break;
    case 98:
      breakLoop = true;
      break;
    default:
      std::cout << "Press correct button!!!\n";
      break;
    }
  }
  std::cout << "End\n";
}