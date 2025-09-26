python-dotenv: Load Environment Variables from a .env File
=========================================================

**Why I chose this module**

Many apps need API keys, secrets, or settings that shouldn’t be hard-coded.
``python-dotenv`` lets you keep those values in a local ``.env`` file and
automatically load them into environment variables. It’s simple, widely used,
and demonstrates professional configuration practices.

What this repo shows
--------------------

- How to install and use ``python-dotenv``.
- How to load variables from a ``.env`` file into your program (``app.py``).
- How to safely parse booleans/integers from env vars (``extras/parse_bool_int.py``).
- How to model "nested" settings with double underscores (``extras/load_nested.py``).

Install instructions
--------------------

This module is **not** part of the Python standard library.

1. Create and activate a virtual environment (recommended)::

      python -m venv .venv
      # Windows:
      .venv\Scripts\activate
      # macOS/Linux:
      source .venv/bin/activate

2. Install dependencies::

      pip install -r requirements.txt

Set up your .env
----------------

1. Copy the example file::

      cp .env.example .env
      # On Windows (PowerShell):
      copy .env.example .env

2. Open ``.env`` and change values as needed (e.g., put your real API key).

Run the demos
-------------

**Basic load (app.py)**::

    python app.py

You should see the values from your ``.env`` printed to the console.

**Parsing types (extras/parse_bool_int.py)**::

    python extras/parse_bool_int.py

Demonstrates converting environment variables into booleans and integers.

**Nested config convention (extras/load_nested.py)**::

    python extras/load_nested.py

Reads the ``.env`` as a dict and transforms keys with double-underscores
(e.g., ``NESTED__DATABASE__URL``) into a nested dictionary structure.

Common pitfalls & tips
----------------------

- Do **not** commit real secrets. Commit ``.env.example`` only.
- ``load_dotenv()`` looks for ``.env`` in the current working directory by default.
- In Docker or production, env vars often come from the platform—``python-dotenv`` is most useful locally and in dev/test.

Potential applications
----------------------

- Local development of apps that use API keys (Google, OpenAI, Stripe, etc.).
- Switching configurations by environment (dev/staging/prod) without code changes.
- Teaching best practices for secure configuration management.
