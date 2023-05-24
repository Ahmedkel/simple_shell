int exit_status(int action, int new_status)
{
	static int status;

	if (action == 1)
		status = new_status;
	return (status);
}
