#lang sicp
(#%require sicp-pict)

(define (polyline vectors)
  (if (null? (cdr vectors))
      nil
      (cons (make-segment (car vectors)
                          (cadr vectors))
            (polyline (cdr vectors)))))

(define wave
  (segments->painter
   (append (polyline (list (make-vect 0 0.87)
                           (make-vect 0.13 (/ 5.5 8))
                           (make-vect 0.25 0.75)
                           (make-vect (/ 3 8) 0.75)
                           (make-vect (/ 2.6 8) (/ 7.6 8))
                           (make-vect (/ 3 8) 1)))
           (polyline (list (make-vect (/ 5 8) 1)
                           (make-vect (/ 5.4 8) (/ 7.6 8))
                           (make-vect (/ 5 8) 0.75)
                           (make-vect 0.75 0.75)
                           (make-vect 1 (/ 3.5 8))))
           (polyline (list (make-vect 1 0.25)
                           (make-vect (/ 5 8) 0.5)
                           (make-vect 0.75 0)))
           (polyline (list (make-vect (/ 4.6 8) 0)
                           (make-vect 0.5 0.25)
                           (make-vect (/ 3.4 8) 0)))
           (polyline (list (make-vect 0.25 0)
                           (make-vect (/ 3 8) 0.5)
                           (make-vect (/ 2.15 8) (/ 5 8))
                           (make-vect (/ 1 8) (/ 3 8))
                           (make-vect 0 (/ 5 8))))
           (polyline (list (make-vect (/ 3.4 8.0) (/ 6.7 8.0))
                           (make-vect (/ 4.6 8.0) (/ 6.7 8.0)))))))

(define (right-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (right-split painter (- n 1))))
        (beside painter (below smaller smaller)))))

(define (up-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (up-split painter (- n 1))))
        (below painter (beside smaller smaller)))))

(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up (up-split painter (- n 1)))
            (right (right-split painter (- n 1))))
        (let ((corner (corner-split painter (- n 1))))
          (beside (below painter up)
                  (below right corner))))))

(define (square-limit1 painter n)
  (let ((quarter (corner-split painter n)))
    (let ((half (beside (flip-horiz quarter) quarter)))
      (below (flip-vert half) half))))


(define (square-of-four tl tr bl br)
  (lambda (painter)
    (let ((top (beside (tl painter) (tr painter)))
          (bottom (beside (bl painter) (br painter))))
      (below bottom top))))

(define identity (lambda (x) x))

(define (square-limit2 painter n)
  (let ((combine4 (square-of-four flip-vert rotate180
                                  identity flip-horiz)))
    (combine4 (corner-split painter n))))
