void Platform_DISPOSE (void **mem);
/*================================== Header ==================================*/

extern void free (void *ptr);

void Platform_DISPOSE (void **mem)
{
  free(*mem);
  *mem = 0;
}
