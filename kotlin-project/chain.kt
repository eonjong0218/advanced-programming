class Calculator {
    private var result: Double = 0.0

    fun add(value: Double): Calculator {
        result += value
        return this // 자기 자신 반환
    }

    fun subtract(value: Double): Calculator {
        result -= value
        return this // 자기 자신 반환
    }

    fun multiply(value: Double): Calculator {
        result *= value
        return this // 자기 자신 반환
    }

    fun divide(value: Double): Calculator {
        if (value != 0.0) {
            result /= value
        }
        return this // 자기 자신 반환
    }

    fun getResult(): Double {
        return result
    }
}

fun main() {
    val calc = Calculator()
    val result = calc.add(5.0)
        .multiply(2.0)
        .subtract(3.0)
        .divide(2.0)
        .getResult()
    println(result) // 출력: 4.0
}
