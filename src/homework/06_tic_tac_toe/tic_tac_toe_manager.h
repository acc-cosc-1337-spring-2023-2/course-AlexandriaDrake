//h
#include "tic_tac_toe.h"
#include<vector>
#include<iostream>

using std::ostream; using std::vector;

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class tic_tac_toe_manager
{
    private:
        vector<tic_tac_toe> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(std::string);

    public:
        void get_winner_totals(int& x, int& o, int& t);
        void save_game(tic_tac_toe);
        friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager);
        
};

#endif

