    for (size_t i = 0; i < q.q3.size() - 1; i++)
    {
        for (size_t j = 0; j < q.q3.size() - 1 - i; j++)
        {
            if (check(&q.q3[j], &q.q3[j + 1]))
            {
                cout<<q.id[j]<<" "<<q.id[j+1]<<" "<<"3";
            }
        }
    }