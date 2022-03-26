 NumberofOperations++;
            PartialSum[i + 1] += 1;
            if (i <= n - k)
                PartialSum[i + k] -= 1;