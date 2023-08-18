program lag_int
   use store
   implicit none

   !> Create vectors and numbers to use in program
   !real    :: x(11)     ! Vector to store x data points
   real    :: x(21)     ! Vector to store x data points
   real    :: xvec(201) ! Vector to store xarray data
   real    :: yvec(201) ! Vector to store y(x) for plotting
   real    :: pvec(201) ! Vector to store P(x) for plotting
   !real    :: y(11)     ! Vector to store calcualted y points
   real    :: y(21)     ! Vector to store calcualted y points
   real    :: s=0.0     ! Polynomial evaluated at value k
   real    :: s2=0.0    ! Polynomial evaluated at value k
   real    :: p         ! Vector Store polynomial coefficents
   real    :: p2        ! Vector Store polynomial coefficents
   real    :: xg        ! Value polynomial is evaluated at
   !integer :: n=11      ! Number of data points
   integer :: n=21      ! Number of data points
   integer :: i,j,k     ! Integers used while looping

   print *, "------------------------------------------"
   print *, "Lagrange interpolation of Runge's funciton"
   print *, "------------------------------------------"

   !! Code to evaluate polynomial at one xi value !!

   print *, "Evaluation of polynomial at given x value"

   ! Discrete x values for (a)
   ! x=(/ -1.0,-0.8,-0.6,-0.4,-0.2,0.0,0.2,0.4,0.6,0.8,1.0 /)
   ! Discrete x values for (b)
   x=(/ -1.0,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.0, &
         0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0/)

   ! Runge function evaluated at xi
   y=1.0/(1.0+25.0*x**2.0)

   ! User entered value to evaluate the function
   print *, 'Enter value used to evaluate the polynomial:'
   read(*,*) xg

   ! Evaluate polynomial at inputed value
   do i = 1,n
      p=1.0
      do j = 1,n
         if (i.ne.j) then
            p=p*((xg-x(j))/(x(i)-x(j)))
         end if
      end do
      s=s+(p*y(i))
   end do

   print *, "Calulated value of polynomial at xi=", xg, "is P(x)=", s

   !! Evaluate polynomial over a range of values !!

   ! Generate an array of x values
   xvec(1) = -1.0
   do i = 2, 201
      xvec(i) = xvec(i-1)+0.01
   end do

   ! Loop through to caculate P(x) and y(x)
   do i = 1, size(xvec)
      yvec(i)=1.0/(1.0+25.0*xvec(i)**2.0)
      s2=0.0
      do j = 1,n
         p2=1.0
         do k = 1,n
            if (j.ne.k) then
               p2=p2*((xvec(i)-x(k))/(x(j)-x(k)))
            end if
         end do
         s2=s2+(p2*y(j))
      end do
      pvec(i) = s2
   end do
   !print *, pvec

   ! Genertate data for plot
   call storedata(xvec,yvec,pvec)

end program
