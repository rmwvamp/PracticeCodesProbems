 for (auto kit = DivisorsCount[it->first].begin(); kit != DivisorsCount[it->first].end(); ++kit)
        {
            cout << "hello2" << endl;
            cout << *kit << endl;
            FrequencyCount[*kit] += it->second;
        }