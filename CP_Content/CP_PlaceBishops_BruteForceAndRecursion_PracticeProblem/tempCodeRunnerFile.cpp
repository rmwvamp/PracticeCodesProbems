for (auto &x : BishopsPlaced)
    {
        if (abs(PrevRow - row) == abs(PrevCol - col))
        {
            return 0;
        }
    }