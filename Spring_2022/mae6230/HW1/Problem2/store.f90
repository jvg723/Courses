module store
   implicit none
   contains
      subroutine storedata(xvec,phi_ext,x,phi_cd,phi_ct)
         real, intent(in), dimension(:) :: xvec,phi_ext,x,phi_cd,phi_ct
         integer :: size_xvec, size_pext, size_x,size_pcd,size_pct, i
         size_xvec = size(xvec)
         size_pext = size(phi_ext)
         size_x = size(x)
         size_pcd = size(phi_cd)
         size_pct = size(phi_ct)
         if (size_xvec /= size_pext) then
            print *, 'Array size mismatch'
         else
            open(unit=1, file='data.dat')
            do i = 1,size(xvec)
               write(1,*) xvec(i), ' ', phi_ext(i), ' ', x(i), ' ', phi_cd(i), ' ', phi_ct(i)
            end do
         end if
      end subroutine storedata
end module store
