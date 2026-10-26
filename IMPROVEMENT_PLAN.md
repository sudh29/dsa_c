---
repo: dsa_c
review_date: 2026-10-26
current_score: 8.7
target_score: 9.6
---

# Repository Improvement Plan: `dsa_c`

> **Hiring-Bar Audit Target:** AI Engineer / Staff IC / Systems Architect (~8 years experience)  
> **Evaluation Threshold:** 9.5+ / 10.0  
> **Current Overall Score:** **8.7 / 10.0** (Delta to 9.5 bar: +0.8)

---

## 1. Baseline Scorecard & Gaps

| # | Criterion | Weight | Score | Primary Gap / Finding |
|---|---|:---:|:---:|---|
| 1 | **Correctness & functionality** | 15% | **8.8** | All 390 programs compile with `-Werror` and run without crashing in 8s. Gap: Only 7/390 (1.8%) programs have programmatic test assertions (`assert()`); 383 files just print with `printf()`. |
| 2 | **Architecture & design** | 15% | **9.3** | Clean 16-module hierarchy, pure C11 standard, idiomatic low-level constructs. Gap: Common utilities (e.g. dynamic array, linked list nodes) re-implemented repeatedly across files without a lightweight common header library. |
| 3 | **Code quality** | 10% | **8.8** | Zero warnings under `-std=c11 -Wall -Wextra -Werror -O2`. Gap: Lacks `.clang-format` configuration; formatting varies; no static analysis (`clang-tidy` / `cppcheck`). |
| 4 | **Testing & CI** | 15% | **6.8** | Blazing fast parallel test runner (8s for 390 files). Gap: Total absence of remote GitHub Actions CI (`.github/workflows/` does not exist); test runner only checks compilation and process exit code 0 rather than validating outputs. |
| 5 | **Security** | 10% | **9.6** | Zero hardcoded secrets or credentials. Zero third-party dependencies. Verified clean ASan runs on sample dynamic memory programs. |
| 6 | **Reliability & performance** | 10% | **9.0** | 8-second execution across 390 programs, clean -O2 optimization. Gap: AddressSanitizer and LeakSanitizer are not integrated into `scripts/compile_and_test.sh` or Makefile. |
| 7 | **DevEx & ops** | 10% | **8.4** | Clean Makefile with `test` and `clean`. Gap: Makefile lacks targets for formatting, ASan, or problem catalog auditing; no Dockerfile or DevContainer. |
| 8 | **Documentation** | 5% | **9.2** | 10.8KB root README with matrix; 16 module guides. Gap: Missing automated catalog audit script (`scripts/audit_c_catalog.py`). |
| 9 | **Repo hygiene** | 5% | **8.8** | MIT License, clean git history. Gap: Untracked `AGENTS.md`; missing `.clang-format`; missing CI workflows. |
| 10 | **Impact & clarity** | 5% | **9.5** | Monumental scope: 390 pure C11 problem solutions demonstrating deep mastery of memory layout, pointers, and algorithms without high-level language abstractions. |

---

## 2. Ranked Gaps (Impact ÷ Effort)

| Rank | Gap Description | Affected Criterion | Impact | Effort | Priority |
|:---:|---|---|:---:|:---:|:---:|
| 1 | Setup GitHub Actions CI matrix (`gcc-12`, `clang-14`, `clang-asan`) | Testing & CI, Hygiene | High | S | Phase 1 |
| 2 | Add AddressSanitizer & UBSan support (`-s / --sanitize`) to `compile_and_test.sh` & Makefile | Testing & CI, Reliability | High | S | Phase 1 |
| 3 | Port `audit_c_catalog.py` to audit assertion coverage, C11 standard adherence, and program counts | Documentation, DevEx | High | S | Phase 1 |
| 4 | Upgrade programs to include non-interactive `assert(...)` test suites (phased across modules) | Correctness, Testing | High | L | Phase 1 & 2 |
| 5 | Add `.clang-format` and `make check-format` quality gate | Code Quality, Hygiene | Medium | S | Phase 2 |
| 6 | Add Dockerfile and DevContainer configuration | DevEx & Ops | Medium | M | Phase 3 |

---

## 3. Phased Action Plan

### Phase 1: MVP-Essential (Target: Cross 9.5 Bar)

Focus on establishing remote CI, AddressSanitizer test automation, catalog auditing, and automating assertions across priority modules.

#### Task 1.1: GitHub Actions Remote CI Pipeline
- **Description:** Create `.github/workflows/ci.yml` that checks out code, runs catalog audit, and verifies compilation and testing across GCC and Clang compilers.
- **Why:** The repository currently has zero automated CI gates on pushes and pull requests.
- **Files Affected:** `.github/workflows/ci.yml`.
- **Acceptance Criteria:** CI runs and passes on pushes to `main` and `dev`.
- **Effort:** Small.
- **Score Delta:** Testing & CI: +1.2, Repo Hygiene: +0.4.

#### Task 1.2: Add AddressSanitizer Support to Test Runner
- **Description:** Update `scripts/compile_and_test.sh` and `Makefile` to accept `--sanitize` / `-s` (passing `-fsanitize=address,undefined -fno-omit-frame-pointer`) and add `make test-asan`.
- **Why:** Manual pointer manipulation in pure C requires continuous automated memory safety validation to prevent buffer overflows and memory leaks.
- **Files Affected:** `scripts/compile_and_test.sh`, `Makefile`.
- **Acceptance Criteria:** `make test-asan MODULE=0_basics` executes cleanly with sanitizers enabled.
- **Effort:** Small.
- **Score Delta:** Testing & CI: +0.4, Reliability: +0.3.

#### Task 1.3: Problem Catalog & Quality Auditor (`scripts/audit_c_catalog.py`)
- **Description:** Port the catalog auditor from `dsa_cpp` to scan all 16 modules, count programs, measure `assert()` adoption rate, detect non-standard headers, and print a formatted summary table. Wire to `make audit`.
- **Why:** Provides transparent, automated telemetry into repository quality and coverage.
- **Files Affected:** `scripts/audit_c_catalog.py`, `Makefile`.
- **Acceptance Criteria:** `make audit` prints summary table with 0 errors.
- **Effort:** Small.
- **Score Delta:** DevEx & Ops: +0.4, Documentation: +0.2.

#### Task 1.4: Automate Assertions in Priority Modules (Tier 1 Modules)
- **Description:** Add `<assert.h>` test assertions in place of simple `printf()` in core modules: `0_basics/`, `1_array/`, `3_string/`, `4_search_sort/`, and `14_dynamic_programming/`.
- **Why:** Guarantees that algorithms produce correct mathematical results rather than just returning 0.
- **Files Affected:** Core files in targeted directories.
- **Acceptance Criteria:** `assert(maxSubarraySum(...) == 9);` etc. present and verified.
- **Effort:** Large.
- **Score Delta:** Correctness & Functionality: +0.6, Testing & CI: +0.6.

---

### Phase 2: Hardening & Code Formatting (Target: 9.6+)

#### Task 2.1: Clang-Format Integration
- **Description:** Add `.clang-format` adhering to Google C style or Linux kernel style, and add `make format` and `make check-format` targets to the Makefile.
- **Why:** Eliminates stylistic drift across 390 programs.
- **Files Affected:** `.clang-format`, `Makefile`.
- **Acceptance Criteria:** `make check-format` validates all `.c` files.
- **Effort:** Small.
- **Score Delta:** Code Quality: +0.4, Repo Hygiene: +0.3.

#### Task 2.2: Expand Assertions Across Remaining 11 Modules
- **Description:** Progressively convert the remaining 11 modules (`2_matrix`, `5_linklist`, `6_binary_tree`, `7_bst`, `8_greedy`, `9_backtracking`, `10_stack_queues`, `11_heap`, `12_graph`, `13_Trie`, `15_bit_manipulation`) to 100% automated assertion coverage.
- **Why:** Brings `dsa_c` to full parity with `dsa_cpp` (100% assertion coverage).
- **Files Affected:** `.c` files in remaining modules.
- **Acceptance Criteria:** `audit_c_catalog.py` reports 100.0% assertion coverage.
- **Effort:** Large.
- **Score Delta:** Correctness: +0.3, Testing: +0.4.

---

### Phase 3: Nice-to-Have & Tooling (Target: 9.7+)

#### Task 3.1: Containerized Hermetic Build Environment
- **Description:** Add `Dockerfile` and `.devcontainer/devcontainer.json` configured with GCC 13, Clang 18, and Make.
- **Why:** Guarantees instant zero-dependency build setup on any developer workstation.
- **Files Affected:** `Dockerfile`, `.devcontainer/devcontainer.json`.
- **Acceptance Criteria:** `docker run make test` succeeds cleanly.
- **Effort:** Medium.
- **Score Delta:** DevEx & Ops: +0.3.

---

## 4. Projected Score Progression

| Phase | Milestone | Expected Score | Delta |
|:---:|---|:---:|:---:|
| **Baseline** | Current audit baseline | **8.7** | — |
| **Phase 1** | Remote CI workflow, ASan flag, catalog auditor, core module assertions | **9.5** | +0.8 |
| **Phase 2** | Clang-format gate, 100% assertion coverage across all 390 files | **9.6** | +0.1 |
| **Phase 3** | Hermetic Dockerfile & DevContainer configuration | **9.7** | +0.1 |

---

## 5. Definition of Done for Reaching 9.5+

- [ ] Remote GitHub Actions CI pipeline running on push and PR.
- [ ] `compile_and_test.sh` and Makefile support `--sanitize` and ASan test suite.
- [ ] `make audit` script tracks program count and assertion adoption.
- [ ] At least core modules enforce `assert()` validations.
- [ ] Zero compiler warnings under `-std=c11 -Wall -Wextra -Werror -O2`.
