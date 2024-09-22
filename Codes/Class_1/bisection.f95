program bisection
    implicit none

    interface
        function f(x)
            real, intent(in) :: x
        end function f
    end interface

    real :: x0, x1, x2
    real :: f0, f1, f2
    integer :: i, it

    print *, "Enter x1 and x2: "
    read (*, *) x1, x2

    print *, "Enter number of iterations: "
    read (*, *) it

    do i = 0, it
        if (abs(x2 - x1) < 0.0005) then
            exit
        end if

        x0 = (x1 + x2) / 2

        f0 = f(x0)
        f1 = f(x1)
        f2 = f(x2)

        if (f0 == 0) then
            exit
        else if (f0 * f1 < 0) then
            x2 = x0
        else if (f0 * f2 < 0) then
            x1 = x0
        else 
            print *, "The root is not in the range ", x1, " ", x2
            exit
        end if

    end do

    print *, "The root of the equation is: ", x0
            
end program bisection

function f(x)
    
    implicit none

    real :: f
    real, intent(in) :: x

    f = x * x - 4 * x - 10

end function f