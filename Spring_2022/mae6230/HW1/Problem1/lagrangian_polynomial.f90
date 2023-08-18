program lagrangian_polynomial
   implicit none
   real :: x(4), y(4),s=0.0,p,k
   integer :: i,j,n

   print *, "=================================="
   print *, "Program for Lagrane interpolation"
   print *, "=================================="

   ! points
   x = (/ 3.35,3.40,3.50,3.60 /)
   y = (/ 0.2985,0.294118,0.285714,0.277778 /)

   print *, 'Langrange interpolation'

   print *, 'Number of terms?'
   read(*,*)n

   print *, 'Enter the data point to calculate the value of polynomial'
   read(*,*)k

   do i = 1,n
      p=1.0
      do j = 1,n
         if ( i.ne.j ) then
            p=p*((k-x(j))/(x(i)-x(j)))
         end if
      end do

      s=s+(p*y(i))
   end do

print *, "Calulated value of polynomial - ",s

end program
