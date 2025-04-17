/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:41:51 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/16 21:32:34 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {

  int num = rand() % 3;
  switch (num) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  default:
    return new A();
  }
}

void identify(Base *p) {

  if (dynamic_cast<A *>(p))
    std::cout << "A";
  else if (dynamic_cast<B *>(p))
    std::cout << "B";
  else if (dynamic_cast<C *>(p))
    std::cout << "C";
  else
    std::cout << "UNKNOWN";
  return;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A";
    return;
  } catch (std::bad_cast &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B";
    return;
  } catch (std::bad_cast &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C";
    return;
  } catch (std::bad_cast &e) {
  }
  std::cout << "UNKNOWN";
  return;
}

int main(int ac, char **av) {

  (void)ac;
  (void)av;
  srand(time(0));

  Base *ptr = generate();

  std::cout << "Type of generated Class, identified using ... " << std::endl;
  std::cout << "... pointer:   ";
  identify(ptr);
  std::cout << std::endl;
  std::cout << "... reference: ";
  identify(*ptr);
  std::cout << std::endl;

  delete ptr;
  return 0;
}