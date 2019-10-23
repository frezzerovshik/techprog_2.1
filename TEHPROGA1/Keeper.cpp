//
//  Keeper.cpp
//  T.P.S.2.L.1
//
//  Created by ¿ÚÂÏ ÿ‡‡ÔÓ‚ on 10/10/2019.
//  Copyright © 2019 ¿ÚÂÏ ÿ‡‡ÔÓ‚. All rights reserved.
//
#include "Keeper.hpp"
#include <iomanip>
Keeper::Keeper(Keeper& init) {
    if (cont_k.getSize() != init.cont_k.getSize() && cont_p.getSize() != init.cont_p.getSize() && cont_g.getSize() != init.cont_g.getSize()) {
        throw exc.no_comparable_size_ecx();
    }
    for (int i = 0; i < cont_k.getSize(); ++i) cont_k.addAtIndex(i, init.cont_k.getItemFromIndex(i));
    for (int i = 0; i < cont_p.getSize(); ++i) cont_p.addAtIndex(i, init.cont_p.getItemFromIndex(i));
    for (int i = 0; i < cont_g.getSize(); ++i) cont_g.addAtIndex(i, init.cont_g.getItemFromIndex(i));
}
void Keeper::editing() {
    cout << "Œ·˙ÂÍÚ Í‡ÍÓ„Ó ÍÎ‡ÒÒ‡ ıÓÚËÚÂ ÔÓÏÂÌˇÚ¸?" << endl << "1 - Parents" << endl << "2 - Grandparents" << endl << "3 - Kids" << endl;
    unsigned short i = cin.get();
    switch (i) {
        case 1: {
            cout << " ‡ÍÓÂ ÔÓÎÂ ıÓÚËÚÂ ËÁÏÂÌËÚ¸?" << endl << "1 - ‘»Œ" << endl << "2 - Ó‰ËÚÂÎË" << endl << "3 - ÒÛÔÛ„Ë" << endl << "4 - ‰ÂÚË" << endl << "5 ‰‡Ú‡ ÓÊ‰ÂÌËˇ" << endl << "6 - ‰‡Ú‡ ÒÏÂÚË" << endl << "7 - ‚ÓÁ‡ÒÚ" << endl;
            unsigned short j = cin.get();
            switch (j) {
                case 1: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏÓÂ ‘»Œ" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getFio() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚ÓÂ ‘»Œ" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setFio(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 2: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿.,»‚‡ÌÓ‚ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getParents() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó Ó‰ËÚÂÎˇı" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setParents(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 3: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getSpouse() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó ÒÛÔÛ„Â" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setSpouse(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 4: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿.,»‚‡ÌÓ‚ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getKids() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó ‰ÂÚˇı" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setKids(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 5: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 16.11.1999" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getBirth() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚Û˛ ‰‡ÚÛ ÓÊ‰ÂÌËˇ" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setBirth(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 6: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 16.11.2026" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getDeath() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚Û˛ ‰‡ÚÛ ÒÏÂÚË" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setDeath(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 7: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 20" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getAge() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚È ‚ÓÁ‡ÒÚ" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setAge(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2: {
            cout << " ‡ÍÓÂ ÔÓÎÂ ıÓÚËÚÂ ËÁÏÂÌËÚ¸?" << endl << "1 - ‘»Œ" << endl << "2 - Ó‰ËÚÂÎË" << endl << "3 - ÒÛÔÛ„Ë" << endl << "4 - ‰ÂÚË" << endl << "5 ‰‡Ú‡ ÓÊ‰ÂÌËˇ" << endl << "6 - ‰‡Ú‡ ÒÏÂÚË" << endl << "7 - ‚ÓÁ‡ÒÚ" << endl;
            unsigned short j = cin.get();
            switch (j) {
                case 1: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏÓÂ ‘»Œ" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_g.getSize(); ++k) {
                        if (*cont_g.getItemFromIndex(k).getFio() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚ÓÂ ‘»Œ" << endl;
                            getline(cin, temp);
                            cont_g.getItemFromIndex(k).setFio(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 2: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿.,»‚‡ÌÓ‚ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_g.getSize(); ++k) {
                        if (*cont_g.getItemFromIndex(k).getParents() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó Ó‰ËÚÂÎˇı" << endl;
                            getline(cin, temp);
                            cont_g.getItemFromIndex(k).setParents(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 3: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_g.getSize(); ++k) {
                        if (*cont_g.getItemFromIndex(k).getSpouse() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó ÒÛÔÛ„Â" << endl;
                            getline(cin, temp);
                            cont_g.getItemFromIndex(k).setSpouse(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 4: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿.,»‚‡ÌÓ‚ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_g.getSize(); ++k) {
                        if (*cont_g.getItemFromIndex(k).getKids() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó ‰ÂÚˇı" << endl;
                            getline(cin, temp);
                            cont_g.getItemFromIndex(k).setKids(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 5: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 16.11.1999" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_g.getSize(); ++k) {
                        if (*cont_g.getItemFromIndex(k).getBirth() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚Û˛ ‰‡ÚÛ ÓÊ‰ÂÌËˇ" << endl;
                            getline(cin, temp);
                            cont_g.getItemFromIndex(k).setBirth(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 6: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 16.11.2026" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_g.getSize(); ++k) {
                        if (*cont_g.getItemFromIndex(k).getDeath() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚Û˛ ‰‡ÚÛ ÒÏÂÚË" << endl;
                            getline(cin, temp);
                            cont_g.getItemFromIndex(k).setDeath(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 7: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 20" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_p.getSize(); ++k) {
                        if (*cont_p.getItemFromIndex(k).getAge() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚È ‚ÓÁ‡ÒÚ" << endl;
                            getline(cin, temp);
                            cont_p.getItemFromIndex(k).setAge(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 3: {
            cout << " ‡ÍÓÂ ÔÓÎÂ ıÓÚËÚÂ ËÁÏÂÌËÚ¸?" << endl << "1 - ‘»Œ" << endl << "2 - Ó‰ËÚÂÎË" << endl << "3 - ÒÛÔÛ„Ë" << endl << "4 - ‰ÂÚË" << endl << "5 ‰‡Ú‡ ÓÊ‰ÂÌËˇ" << endl << "6 - ‰‡Ú‡ ÒÏÂÚË" << endl << "7 - ‚ÓÁ‡ÒÚ" << endl;
            unsigned short j = cin.get();
            switch (j) {
                case 1: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏÓÂ ‘»Œ" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getFio() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚ÓÂ ‘»Œ" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setFio(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 2: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿.,»‚‡ÌÓ‚ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getParents() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó Ó‰ËÚÂÎˇı" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setParents(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 3: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getSpouse() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó ÒÛÔÛ„Â" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setSpouse(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 4: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: »‚‡ÌÓ‚‡ ¿.¿.,»‚‡ÌÓ‚ ¿.¿." << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getKids() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚Â Ò‚Â‰ÂÌËˇ Ó ‰ÂÚˇı" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setKids(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 5: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 16.11.1999" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getBirth() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚Û˛ ‰‡ÚÛ ÓÊ‰ÂÌËˇ" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setBirth(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 6: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 16.11.2026" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getDeath() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚Û˛ ‰‡ÚÛ ÒÏÂÚË" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setDeath(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                case 7: {
                    bool success = false;
                    string src;
                    cout << "¬‚Â‰ËÚÂ ËÒÍÓÏ˚Â Ò‚Â‰ÂÌËˇ ‚ ÙÓÏ‡ÚÂ: 20" << endl;
                    getline(cin, src);
                    for (unsigned short k = 0; k < cont_k.getSize(); ++k) {
                        if (*cont_k.getItemFromIndex(k).getAge() == src) {
                            string temp;
                            cout << "¬‚Â‰ËÚÂ ÌÓ‚˚È ‚ÓÁ‡ÒÚ" << endl;
                            getline(cin, temp);
                            cont_k.getItemFromIndex(k).setAge(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if (success == false)
                        cout << "“‡ÍÓÈ Á‡ÔËÒË ÌÂÚ" << endl;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}
void Keeper::print() {
    int n;
    cout << "¬‚Â‰ËÚÂ ¯ËËÌÛ ÔÓÎˇ Ú‡·ÎËˆ˚ ‚˚‚Ó‰‡:" << endl;
    cin >> n;
    cout.setf(ios::fixed);
    cout << "Grandparents" << setw(n) << "|"  << "Parents" << setw(n) << "|" << "Kids" << setw(n) << "|" << endl;
    for (int len = 0; len < 23 + 3 * n; ++len) cout << "-";
    cout << endl;
    unsigned short  max_capacity = 0;
    for (int i = 0; i < 3; ++i) {
        if (cont_p.getSize() > max_capacity)
            max_capacity = cont_p.getSize();
        if (cont_g.getSize() > max_capacity)
            max_capacity = cont_g.getSize();
        if (cont_k.getSize() > max_capacity)
            max_capacity = cont_k.getSize();
    }
    for (unsigned short i = 0; i < max_capacity; ++i) {
        cout.setf(ios::fixed);
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getFio()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getFio()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getFio()<<setw(n)<<"|";
        
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getSpouse()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getSpouse()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getSpouse()<<setw(n)<<"|";
        
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getParents()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getParents()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getParents()<<setw(n)<<"|";
        
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getKids()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getKids()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getKids()<<setw(n)<<"|";
        
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getBirth()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getBirth()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getBirth()<<setw(n)<<"|";
        
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getDeath()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getDeath()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getDeath()<<setw(n)<<"|";
        
        if(i < cont_g.getSize()) cout<< *cont_g.getItemFromIndex(i).getAge()<<setw(n)<<"|";
        if(i<cont_p.getSize()) cout<< *cont_p.getItemFromIndex(i).getAge()<<setw(n)<<"|";
        if(i<cont_k.getSize()) cout<< *cont_k.getItemFromIndex(i).getAge()<<setw(n)<<"|";
        cout<<endl;
        if(i%7==0)
            cout<<endl;
    }
    
    
    
}
