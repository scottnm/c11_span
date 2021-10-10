project('c11_span', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# add_project_arguments('-Dc_std=c11', language : 'c')

exe = executable('c11_span', 'src/main.c',
  override_options : ['c_std=c17'],
  install : true)

test('basic', exe)
