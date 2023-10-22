bool isPowerOfTwo(int n)
{    
  // Check if n is a power of two
  if ((n & (n - 1)) == 0) {
    return true;
  } 
  return false;
}
