function factorial(start, stop)
    if start > stop
        return 1
    end
    if start == stop
        return start
    end
    if stop - start == 1
        return start * stop
    end

    mid = div(start + stop, 2)
    x = Threads.@spawn factorial(start, mid)
    y = Threads.@spawn factorial(mid + 1, stop)

    return fetch(x) * fetch(y)
end

function main()
    n = 10
    result = factorial(1, n)
    println(result)
end

main()
