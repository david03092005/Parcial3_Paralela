function fibonacci(n)
    if n <= 1
        return n
    end

    x = Threads.@spawn fibonacci(n - 1)
    y = Threads.@spawn fibonacci(n - 2)

    return fetch(x) + fetch(y)
end

function main()
    n = 10
    result = fibonacci(n)
    println(result)
end

main()
