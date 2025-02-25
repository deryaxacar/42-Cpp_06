/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:21:03 by deryacar          #+#    #+#             */
/*   Updated: 2025/02/25 19:21:03 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>

using std::cout;
using std::endl;

typedef struct {
    float a, b;
} Data;

class Serializer {
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(const Serializer& copy);
        Serializer &operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
