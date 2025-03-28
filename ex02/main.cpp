/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:21:30 by deryacar          #+#    #+#             */
/*   Updated: 2025/02/25 19:21:30 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    srand(time(0));
    size_t randomNumber = rand();
    Base *ret;
    if (randomNumber % 3 == 0)
        ret = new A;
    else if (randomNumber % 2 == 0)
        ret = new B;
    else
        ret = new C;
    return ret;
}

void identify(Base* p) {
    if (!p) {
        std::cout << "Error: * Null pointer received" << std::endl;
        return;
    } else {
        if (dynamic_cast<A *>(p))
            std::cout << "* Actual type object is A" << std::endl;
        else if (dynamic_cast<B *>(p))
            std::cout << "* Actual type object is B" << std::endl;
        else if (dynamic_cast<C *>(p))
            std::cout << "* Actual type object is C" << std::endl;
    }
}

void identify(Base& p) {
    for (size_t i = 0; i < 3; ++i) {
        try {
            switch (i)
            {
                case 0: {
                    A a = dynamic_cast<A&>(p);
                    std::cout << "& Actual type object is A" << std::endl;
                    break;
                }
                case 1: {
                    B b = dynamic_cast<B&>(p);
                    std::cout << "& Actual type object is B" << std::endl;
                    break;
                }
                case 2: {
                    C c = dynamic_cast<C&>(p);
                    std::cout << "& Actual type object is C" << std::endl;\
                    break;
                }
            }
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}
int main() {
    Base *b = generate();
    
    if (b) {
        identify(b);
        identify(*b);
        delete b;
    } else
        std::cout << "Error: Failed to generate object" << std::endl;
    return 0;
}
