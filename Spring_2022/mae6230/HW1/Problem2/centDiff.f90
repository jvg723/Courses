program centDiff
   use store
   implicit none

   !real    :: a=0.98         ! a value used during x calculation
   real    :: a=0.90         ! a value used during x calculation
   integer :: N=32           ! Max number of steps to take
   integer :: i              ! Integers used while looping
   real    :: xvec(32)      ! Vector to store xarray data
   real    :: phi_ext(32)    ! Vector to store xarray data
   real    :: phi_cd(32)     ! Vector to store CD phi approx
   real    :: phi_ct(32)     ! Vector to store CT phi approx
   real    :: x(32)          ! Varaible to store x during loop
   real    :: xi(32)         ! Variable to store xi during loop
   real    :: j(32)          ! Vector to calcualted j values


   ! Generate an array of x values and exact derivative values
   xvec(1) = -1.0
   xvec(32) = 1.0
   do i = 2, 31
      xvec(i)=xvec(i-1)+0.066
   end do

   ! Generate an array of exact derivative values
   do i = 1, 32
      phi_ext(i)=-8.0*(xvec(i))**7.0
   end do

   ! Generate an array of j values
   j(1) = 0.0
   do i = 2, N
      j(i)=j(i-1)+1.0
   end do

   ! Loop through and calcuate xi and x values
   do i = 1, N
      !xi(i)=-1.0+2.0*j(i)/N
      !x(i)=(1.0/a)*TANH(xi(i)*(ATANH(a)))

      xi(i)=3.14*j(i)/N
      x(i)=COS(xi(i))
   end do

   ! Calculate dphi/dx using cd and ct
   do i = 2, N-1
      phi_cd(i)=((1.0-x(i+1)**8.0)-(1.0-x(i-1)**8.0))/(x(i+1)-x(i-1))
      !phi_ct(i)=(((1.0/COSH(ATANH(a*x(i))))**2.0)/(1.0-(x(i)*a)**2.0))* &
      !          (((1.0-x(i+1)**8.0)-(1.0-x(i-1)**8.0))/(xi(i+1)-xi(i-1)))
      phi_ct(i)=1.0/SQRT(1.0-x(i)**2.0)* &
                (((1.0-x(i+1)**8.0)-(1.0-x(i-1)**8.0))/(xi(i+1)-xi(i-1)))
   end do

   ! Genertate data for plot
   call storedata(xvec,phi_ext,x,phi_cd,phi_ct)

end
