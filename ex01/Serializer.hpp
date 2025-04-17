/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:50:05 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/16 16:13:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

typedef struct Data {
  int num;
  std::string msg;
} Data;

class Serializer {
private:
  Serializer() = delete;
  Serializer(Serializer &other) = delete;
  Serializer &operator=(const Serializer &) = delete;
  ~Serializer() = delete;

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif