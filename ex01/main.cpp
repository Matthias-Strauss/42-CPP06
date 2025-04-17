/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:12:28 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/16 16:40:29 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av) {

  Data dat;
  uintptr_t vptr;
  Data *dptr;

  (void)ac;
  (void)av;

  dat.num = 42;
  dat.msg = "Hello World!";

  std::cout << std::endl;
  std::cout << "Original Adress of Data: " << &dat << std::endl;
  std::cout << std::endl;

  vptr = Serializer::serialize(&dat);

  std::cout << "Serialized: " << vptr << std::endl;

  dptr = Serializer::deserialize(vptr);
  std::cout << "Deserialized: " << dptr << std::endl;
  std::cout << std::endl;

  if (dptr == &dat) {
    std::cout << "Serialization and Deserialization successfull!\nThe "
                 "addresses match."
              << std::endl;
  } else
    std::cout << "Serialization and Deserialization FAILED!\n The "
                 "addresses are a mismatch."
              << std::endl;
  std::cout << std::endl;

  std::cout << "Checking if Data.message is accessible" << std::endl;
  std::cout << "using deserialized address: " << dptr->msg << std::endl;
  std::cout << std::endl;
  return 0;
}