bool isKthBitSet(int n, int k)
{
    int bitposition = 1 << k-1;

    if((n & bitposition) != 0){
        return true;
    }
    else{
        return false;
    }
}
