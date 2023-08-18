program main

  ! Get access to MPI library
  use MPI
  ! No implicitly defined variables
  implicit none
  ! Declare local variables
  integer :: iRank,nProc,comm,ierror,N,np
  ! Declare real varaibles
  real :: a,b,t1,t2,TET

  ! Set N value
  N = 1000000

  ! Time before parallel initiation
  t1 = MPI_Wtime()

  ! Setup the parallel environment
  call MPI_Init(ierror)

  ! Rename the MPI global communicator
  comm=MPI_COMM_WORLD

  ! Get processor information
  call MPI_Comm_Rank(comm,iRank,ierror)
  call MPI_Comm_Size(comm,nProc,ierror)

  ! Assign np
  np = nProc

  ! Time before loop
  t1 = MPI_Wtime()

  do b = 1, N/nProc

   ! Calculate exp(b)
	a = exp(b)

  end do

  ! Time after loop
  t2 = MPI_Wtime()

  ! Total execution time
  TET = t2-t1

  ! Print total execution time
  print*,'The total execution time for ', np, 'processors is ',TET

  ! Finalize MPI
  call MPI_FINALIZE(ierror)

end program main
