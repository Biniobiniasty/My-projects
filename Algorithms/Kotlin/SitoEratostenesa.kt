fun SitoErastotenesa(x: Int)
{
    println(x);
    var tab = IntArray(x);

    var i = 0;
    while(i < x)
    {
        tab[i] = 0
        i++
    }

    i = 2

    while(i <= (sqrt(x.toDouble())).toInt())
    {
        var index: Int = i*2;
        while(index < x)
        {
            tab[index] = 1
            index += i;
        }
        i++
    }



    i = 2;
    while(i < x)
    {
        if(tab[i] == 0)
            print("$i, ")
        i++
    }

}
