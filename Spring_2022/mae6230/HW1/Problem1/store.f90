module store
   implicit none
   contains
      subroutine storedata(x,y,p)
         real, intent(in), dimension(:) :: x,y,p
         integer :: size_x, size_y, size_p, i
         size_x = size(x)
         size_y = size(y)
         size_p = size(p)
         if (size_x /= size_y) then
            print *, 'Array size mismatch'
         else
            open(unit=1, file='data.dat')
            do i = 1,size(x)
               write(1,*) x(i), ' ', y(i), ' ', p(i)
            end do
         end if
      end subroutine storedata
end module store
