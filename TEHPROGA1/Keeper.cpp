//
//  Keeper.cpp
//  T.P.S.2.L.1
//
//  Created by Артем Шарапов on 10/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Keeper.hpp"
Keeper::Keeper( Keeper& init){
    if(cont_k.getSize()!=init.cont_k.getSize() && cont_p.getSize()!=init.cont_p.getSize() && cont_g.getSize()!=init.cont_g.getSize()){
        throw exc.no_comparable_size_ecx();
    }
    for(int i = 0;i<cont_k.getSize();++i) cont_k.addAtIndex(i, init.cont_k.getItemFromIndex(i) );
    for(int i = 0;i<cont_p.getSize();++i) cont_p.addAtIndex(i, init.cont_p.getItemFromIndex(i) );
    for(int i = 0;i<cont_g.getSize();++i) cont_g.addAtIndex(i, init.cont_g.getItemFromIndex(i) );
}
