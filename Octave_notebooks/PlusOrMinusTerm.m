function a = PlusOrMinusTerm(n)
    if mod(n,2) == 0
        PlusOrMinus = 1;
    else
        PlusOrMinus = -1;
    end
    a = PlusOrMinus / factorial(n);
end

