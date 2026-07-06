Rule of 3/5 are implementation rules. They tell you exactly which special member functions you must write to prevent resource leaks or double-frees when your RAII object is copied or moved.

The Problem the Rule of 5 SolvesIf you only write a constructor and destructor (basic RAII), C++ will automatically create copy and 
move operations for you. These default operations perform a shallow copy, which breaks RAII.
