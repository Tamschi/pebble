/*
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


static void clar_print_init(int test_count, int suite_count, const char *suite_names)
{
	(void)test_count;
	printf("Loaded %d suites: %s\n", (int)suite_count, suite_names);
	printf("Started\n");
}

static void clar_print_shutdown(int test_count, int suite_count, int error_count)
{
	(void)test_count;
	(void)suite_count;
	(void)error_count;

	printf("\n\n");
	clar_report_errors();
}

static void clar_print_error(int num, const struct clar_error *error)
{
	printf("  %d) Failure:\n", num);

	printf("%s::%s (%s) [%s:%d] [-t%d]\n",
		error->suite,
		error->test,
		"no description",
		error->file,
		error->line_number,
		error->test_number);

	printf("  %s\n", error->error_msg);

	if (error->description != NULL)
		printf("  %s\n", error->description);

	printf("\n");
}

static void clar_print_ontest(const char *test_name, int test_number, int failed)
{
	(void)test_name;
	(void)test_number;
	printf("%c", failed ? 'F' : '.');
}

static void clar_print_onsuite(const char *suite_name, int suite_index)
{
	/* noop */
	(void)suite_index;
	(void)suite_name;
}

static void clar_print_onabort(const char *msg, ...)
{
	va_list argp;
	va_start(argp, msg);
	vfprintf(stderr, msg, argp);
	va_end(argp);
}
